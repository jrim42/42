### struct

### global

### functions

1. `error_exit`
2. `send_all`

### basic setting

1. argc, port
2. initialize
3. ss
4. socket addres
5. bind
6. listen

### while문

1. select로 이벤트 감지
2. (for)
   1. (if) 새 클라이언트 연결
      1. accept
      2. max, id, fd_set
      3. 연결 메세지
      4. c들에게 메세지 전달
   2. (if) 클라이언트 종료처리
      1. recv
      2. recv 실패
         - 메세지 보내기
         - fd_set, close
   3. (else) 클라이언트 메세지 처리
      - (for) 메세지 보내고 잘 초기화하기
