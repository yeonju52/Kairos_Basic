# KG-kairos

## Part1. 아두이노 - 파이썬

<details>
<summary><strong>w1</strong></summary>
<ol>
<details>
<summary>day1 (231221)</summary>

<h4>Arduino</h4>

    - 컴파일, 링킹
        .c -> .obj + .lib -> .exe || .bin
    - SSD = ROM, CPU = CPU core, RAM = RAM
    - TCP/IP = header를 통해 구분
    - 무선원격자동차 - 모빌리티 서비스 프로젝트에서 한 거랑 동일 (카메라로 보고 동작 제어)

<h4>Arduino IDE</h4>

    - I = 700~800
    - Serial Monitor - Arduino 할 수 있는 것은 업로드, 통신 !
    - 장치관리자: 포트
    - 설정: Tools - Board, Port
    - 한 폴더 당 .ino * 1개
    - 컴파일 올리면, 실행 중단할 수 없다. 실행 중단하고 싶다면, 코드를 통해 끄는 프로세스를 추가해야 한다.

    - angle 값 통신할 때, "a9b10c432d42e\n", "1,3,4,1,56,24\n" => 인덱스가 정해져있는 알파벳이나 구분자로 통일


    - 아두이노, PC에 따라, 부동소수점을 계산하는 방법이 달라서, Float를 쓰는 것을 조심해야 한다.

</details>
</ol>
<ol>
<details>
<summary>day2 (231222)</summary>
<h2>Arduino: avr-gcc (C compiler가 존재)</h2>

    - C compiler가 없으면, 클래스를 작동하기 쉽지 않음
    - 아두이노의 특이점은 컴파일러가 존재해서 클래스가 작동할 수 있다.

    - 컨셉 설계가 잘못되는 경우가 많음 (ex) 현대, 중국..?)

    - 오버로드 - c++는 가능, c는 불가능. 왜냐? 객체지향프로그래밍의 차이
<h2>전자회로</h2>

    - 선형소자: 전압과 전류가 1차 비례
    - 비선형소자:  ex) 반도체 소자
    - 전압은 저항에 의해 떨어짐 (Nv->0v)
    - 저항이 세면, 전압 강하 (실제 적용할 때의 문제)
    - 핸드폰 개발할 때, 계속 죽음. -> 초기화코드와 LCD 키는 코드 사이에 딜레이를 넣으니 해결.
    - 전압원 (이상과 현실이 다르다) - 전압 걸자마자 바로 동작시켜버리면, 큰일남. delay 해라~
    - '전압원 단자 전압 > 전류원 단자 전류'에 대한 문제가 훨씬 많이 발생
    - 전압 관리 > 전류 관리 훨씬 관리(값 조절)하기 쉬움
    - 포토레지스터: 주변 빛에 따라, 저항값을 조절
    - 버튼: pull up & pull down

> LG: 할 수 있어 (많이 한다~~)

<h2>Interrupt</h2>

- 지터 개념 확실하게 이해하기 (느린 거? 빠른 거?)
- 아두이노 변수 토글하는 방법
- 원리 (컴퓨터 아키텍처 부분)
    - clock - Timer: (Oscillator)가 16MHZ마다 신호를 보냄..? => 이게 Timer에 8개 들어가서, 8bit를 채우면 -> Interrupt 발생
- Interrupt 동작 방식
    - Program Counter -> Program 메모리 (명령어 저장) -> Insturction Decoder (명령어 해석) - 레지스터에 저장되어 있는 변수 값을 이용 - 필요한 경우, RAM에 저장 -> DPIO로 결과값이 뜸
    - CPU Core = Program Counter + Introduction Decoder, GPIO
    - RISC (decoder 적음), CISC (decoder 많음)
    - 순서도
        1. 메모리 (Interrupt Vector table + 명령어 모음집)
        2. GPIO2에서 interrupt 발생하면, Interrupt Controller가 감지함.
        3. Interrup Controller가 Program Counter로 전달. 원래의 실행 주소는 Backup register로 들어감
        4. Program Counter가 (Interrupt Vector table)을 가리키고, (interrupt Vector table)에는 실행할 주소가 저장되어 있다. 그 주소의 명령어를 실행한다.
        5. 명령어가 실행이 완료되면, Backup Memory에 있던 주소가 Program Counter로 돌아와 원래대로 실행된다.

- 가변저항: ADC(Analog to Digital Converter)
    - ADC - 10bit
</details>
</ol>
</details>

<details open>
<summary><strong>w2</strong></summary>
<ol>
<details>
<summary>day3 (231226)</summary>

    1. namespace
    2. class ___.cpp
    3. static 클래스
    4. LPF
        - 용도: 초음파 센서에서 튀는 값을 잡는다.
        - 2~3가지 방법
            - LRC 회로
            - (SW) ADC
            - SW를 반도체 칩으로 만든다.
    5. Seiral 통신 vs I2C 통신
        - Serial 통신: PC to PC
        - I2C 통신: IC to IC
    6. 서비스 로봇의 UI (클릭, GUI) - Web > QT5 > COCO UI 이용
    7. OLED 연결
</details>
</ol>
<ol>
<details>
<summary>day4 (231227)</summary>

    - 그래픽으로 돌아가는 경우
        - 셋업 - while() - e.c = 캐릭터이동 - 그래픽 - GPU
        - GPU: 행렬 계산 가능한 모듈이 여러개 들어있음 (Frame Buffer)
        - CPU: 느림
    - Poor Arduino
        - I2C, SPI 통신
        - Frame Buffer는 아두이노 안에
        - ESP32의 경우, 카메라가 달려 있음. 30 frame 구현하기 위해, 메모리가 탑재되어 있음
        - Text <-> Grahpic
            - Graphic은 픽셀에 찍으면 됨.
            - Text: 10x10 글씨를 100x100 디스플레이에 채우는 형식 (LUT 이용)
    - 화면 가로 세로 변환: 가속도 센서로 감지 -> OpenGL로 계산
    - 가속도: 위아래(수직하강..?), 자이로 센서: 회전 감지
    - 자이로 센서는 전기를 많이 먹어서, 사실 잘 안 씀. 근데 엄청 정확
    - 로봇에서 쓰이는 이유: pitch, roll, yaw 구하기. 이를 통해, trasit
</details>
</ol>

## Part2. 기초로봇공학

<ol>
<details open>
<summary>day5 (231228)</summary>
    
### 1. 로봇학 개론

    - 아시모프의 로봇 3원칙
    - 산업용 오토메이션: 컴퓨터를 기본으로 하는 시스템에 관한 기술
    - 로봇의 운동 제어 (물체의 이동 및 위치 결정)
        - 사람의 위치 결정 -> 로봇으로 확장: 제어 편차와 블럭선도 (제어계를 이용)
    - 퍼텐쇼미터와 인코더(와 스트레인게이지)
    - 로봇을 구현하기 어려운 부분(사람과 로봇의 형태 비교): 6가지의 감각
        - 촉각 센서
            - 진동 느끼기
            - 미지의 중량을 느끼는 거 (날달걀 껍질이 얇은 것 같아)
        - 길항 운동
- T자형 인재? : 내가 잘하는 건 하나 있어야 하고, 주변 지식도 존재해야 하는 ..?

### 2. 로봇동력학 / 기구학

    - 산업용 로봇의 기본 구조와 좌표계
        - 극좌표형 로봇 (극좌표계 사용): 반도체 - 와이퍼 이동같은 것을 빠르게 실행해야할 때
        - 직교 좌표계(3D 프린팅), 원통 좌표계
    - DoF: 6자유도 (x축, y축, z축, pitch, roll, yaw)
    - 도장용 로봇의 교시법 - 목표값 제어 (피드백으로 제어한다)
    - 로봇의 기동 범위: 크고 넓다 vs 좁고 작다 - 작을수록 쓰일데가 많겠지.. 반도체라던지..?
    - 로봇 기동 방법: 프로그래밍한대로
    - 로봇 컨트롤 형태: 라플라스 변환(ex. 노이즈캐슬링), 증폭기(=가중치)/신호처리 등, 로봇이 교시가 된 상태에서 진행이 된다.
    - 모터의 피드백: 모터 회전수의 과도 응답
    - 양자화 - 여기서도 양자화가 나온다! (ADC)
    - 로봇의 제어부의 상관관계
    - 스트레인 게이지 원리와 이용: 스트레인 게이지 응용의 예시 - 엘레베이터, 진동..?

### 3. 전자회로
    - 전기회로 vs 전자회로
    - 반도체 소자: 비선형 소자
    - V = IR, P = IV
    - 계측기(전압, 전류, 저항 측정)
        - 이상적인 그래프 != 현실적인 그래프 why? 지연계, 전류원에서 문제가 자주 발생
    - 키르히호프의 전압 법칙 / 전류 법칙
    - 직렬 저항기 - 전압 분할, 병렬 저항기 - 전류 분할
    - RLC
        - C: capcitor(커패시터): 충전-방전 <-> 인덕터
    - 전자회로 (RLC + 다이오드/트랜지스터)
    - 반도체: 부도체의 역할이 더 확실해야 오동작이 적겠지?
        - 다이오드 - 극성 여부
            - 전기를 정확하게 막는 게(전기 차단) 훨씬 중요: 역방향 바이어스(닫힌 문)
            - 정류 역할
        - 트랜지스터: 양극성 (p형 반도체, n형 반도체): pnp, npn
            - 증폭, 스위치 역할
    - 로봇 위치 측정: 휘트스톤 브리지, 비교기 등으로 동작, 더 좋은 방법으로 위치를 측정할 수 있음
        - 로봇에 문제가 생겼다..? 마지막 위치를 모르기 때문에(원점이 아닌 경우가 있을 수도), 처음부터 다시 초기화할 필요가 있다. 
    - 로봇 직류 모터를 위한 회로: 속도를 증감하려면, 감속기를 이용하거나 SW로 구현하면 됨. (내가 SW로 구현할 줄 안다면, GOOD!)
    - 로봇과 컴퓨터 제어: 누적 공차를 없애야 함. 양자화 샘플링 과정에서 (Analog to Discrete) 오차가 발생하기 때문
    - 인코더: 컴퓨터의 인코더와 비슷하짐잔, 분야가 다름 (리니어 인코더와 로터리 인코더가 존재)
    - 엔드 이펙트
        - ??? 그리퍼(3가지): 공기의 팽창, 자석 흡입력, 나사 이용
        - 링크형 그리퍼: 공기압을 이용 (소형 공기압 실린더)

### 4. 로봇학 행렬 / 선형 대수학
    - 

</details>
</ol>


</details>