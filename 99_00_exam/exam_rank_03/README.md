### 01. 밑준비
1. argc 확인하기
	- 2가 아니면 error
2. file 읽기모드로 열기 (fopen)
	- 파일 열람에 문제가 생기면 error
3. file에서 기본 map info 읽어오기 (fscanf)
	- w, h, background 3개를 만족하지 못하면 error
	- w와 h가 0보다 크고 300보다 같거나 작지 않으면 error
4. map allocation 및 initiation
	- char ** 할당하기
	- map의 각 char를 info->background로 채우기
---
### 02. micro_paint / mini_paint
1. file에서 paint 조건 읽어오기 (fscanf)
	- (micro) type, x, y, w, h, color 6개를 만족하지 못하면 error
	- (mini) type, x, y, r, color 5개를 만족하지 못하면 error
	- micro_paint / mini_paint 호출하기
	- (+) fscanf의 retuern value가 -1이 아닌 경우 error
2. micro_paint / mini_paint
	1. micro_paint
		- if ((rect->type == 'r' && ret == 2) || (rect->type == 'R' && ret != 0))
	2. mini_paint
		- if ((cir->type == 'c' && ret == 2) || (cir->type == 'C' && ret != 0))
---
### 03. map 출력 및 마무리
1. 조건이 적용된 map 출력하기
2. map free (free)
3. file close (fclose)