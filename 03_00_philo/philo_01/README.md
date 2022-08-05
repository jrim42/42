## philosophers code flow
---
### 01. parameter
1. argc는 반드시 5개 혹은 6개여야 한다.
2. philo_atoi
	- 매개변수에는 숫자를 제외한 문자가 등장하면 안된다.
	- INT_MAX 범위 내의 양수여야한다.
3. 0 이하의 수가 들어와서는 안된다.
4. argv[5] (num_must_eat)이 존재하지 않는 경우 -1로 설정해둔다.

---
### 02. init & allocation
1. init_info
	- 포크 뮤텍스 배열 할당
	- 철학자 구조체 배열 할당
2. init_philo
3. create_philo
	- 철학자 thread 생성
	- routine으로 보내줄게

---
### 03. routine
1. 포크 잡아줄게
	- 왼쪽 포크와 오른쪽 포크 뮤텍스에 대한 lock
	- print_routine으로 출력하기
2. 먹어줄게 / 포크 내려놔줄게
	- t_eat
	- print_routine으로 출력하기
	- 먹은 후에는 last_eat을 갱신해준다
	- 왼쪽 포크와 오른쪽 포크 뮤텍스에 대한 unlock
3. 잠자줄게
	- t_sleep
	- print_routine으로 출력하기
4. 생각해줄게
	- print_routine으로 출력하기
---
### 04. monitoring
1. 죽어줄게
	- now - last_eat >= t_die 인 경우 철학자는 죽게된다.
2. 배불러줄게 (num_must_eat 존재하는 경우)
	- stuffed_philo == n_eat 인 경우 시뮬레이션 종료

---