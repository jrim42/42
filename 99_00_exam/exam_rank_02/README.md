### get_next_line

1. utils
	- ft_strlen
	- ft_strchr
	- ft_strndup
	- ft_strjoin

### ft_printf

1. utils
	- ft_strlen
	- ft_strndup
	- ft_numlen_base
	- ft_putnbr_base
		- 재귀
		- num >= base인 경우 아래를 호출
			- ft_putnbr_base(num / base, base);
			- ft_putnbr_base(num % base, base);
		- else일 때는 dec와 hex 중에 골라서 write
	- ft_putnstr
		- 인자로 들어온 str을 len만큼 출력한다.
	- ft_putnchar
		- 인자로 들어온 문자 ch를 len만큼 출력하고
		- (*printed)++

2. ft_printf
	- input 존재하는지 검사하기
	- va_start(ap, input)
	- parse_input에서 출력하고 return len도 받아오기
	- va_end(ap)

3. parse_input
	- input을 쭉 돌면서... (while)
		- %가 아닌 경우에는 출력하고 len++
	- %를 만나면
		- 먼저 find_type
		- type을 제대로 확인한 경우에는 %이후부터 (type + 1) - input 만큼 strndup
			- type이 존재하지 않으면 input++;
		- print_with flag에 복제한 str을 보내서 출력하고 길이도 받아온다
		- input의 포인터 이동
	- 다시 반복...

4. find_type
	- 서식자의 위치를 확인한다.
	- 숫자와 정밀도를 의미하는 .을 뛰어넘고
	- s, d, x 중 하나를 만나면 해당 addr를 return
	- 찾지 못한 경우는 NULL return

5. print_with_flag
	- init_struct로 구조체 초기화
	- parse_flag에서 flag 분석
	- type == s
	- type == d
	- type == x
	- 앞서 할당했던 format str을 해제하고 길이를 return해준다

6. parse_flag
	- wid
	- dot를 만나면 dot = 1로 전환하기
	- prc는 dot == 1인 경우에만
	- flag = (flag * 10) + (format[i] - '0')

6. print_str
	- str == NULL인 경우 (null)
	- dot이 존재하고 len < prc이면 prc = len
	- dot이 존재하지 않으면 prc = len
	- wid - prc 만큼 공백을 출력하고 (printed++)
	- printed += prc, 그만큼 str 출력

7. print_num
	- num이 존재하지 않고 dot이 없으면 (prc도 없겠죠 그럼) wid만큼 공백 출력하고 리턴
	- num이 존재하는 경우
	- prc < len 이면 prc = len
	- num이 음수면 prc++
	- wid - prc 만큼 공백을 먼저 출력하고 (printed++)
	- 음수인 경우 -를 출력해준다
	- prc - len 만큼 0을 출력하고, -> 얘만 ft_putnchar 사용하지 않음
	- printed += prc
	- ft_putnbr_base로 수 출력해주기

8. 구조체
	- flag
		- wid : width
		- dot : . 유무
		- prc : precision
		- type
	- arg
		- str : s
		- num : d
		- u_num : x
		- len : length
		- printed : 실제로 출력된 길이