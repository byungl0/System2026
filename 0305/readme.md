# 📅 3월 5일 수업 정리 보고서

## 📝 1. 수업 개요 및 주요 내용
본 저장소는 3월 5일 진행된 시스템 환경 구축 및 버전 관리 수업 내용을 정리한 공간입니다.

### 💡 주요 학습 내용
* **유닉스(Unix) / 리눅스(Linux) 소개:** 현대 운영체제의 근간이 되는 유닉스/리눅스 환경의 기본 개념 이해
* **GitHub 사용법:** 버전 관리를 위한 기초적인 워크플로우 학습 (`git` -> `SourceTree` -> `GitHub`)
* **학습 커리큘럼 추천:** 향후 시스템 및 개발 환경 학습을 위한 로드맵 확인

---

## 💻 2. 수업 실기 및 환경 구축 내용

### 🛠️ 개발 환경 구축 단계
1. **Windows Terminal 설치:** 다중 탭과 커스텀이 가능한 윈도우 차세대 터미널 환경 구축
2. **WSL2(Windows Subsystem for Linux 2) 설치:** 윈도우 내 가상화 기반 리눅스 커널 구축
3. **기술 보고서 작성 및 버전 관리:** `wsl2.pdf` 파일을 생성한 뒤, Git을 통해 GitHub 원격 저장소에 업로드 완료

---

## 📑 3. 핵심 기술 정리 (VM, JVM, WSL2)
수업 중 실기로 정리한 가상화 및 실행 환경 기술의 핵심 요약입니다.

### [cite_start]1) VM (Virtual Machine, 가상 머신) [cite: 1]
* [cite_start]**개념:** 하나의 물리 컴퓨터 안에서 **하이퍼바이저(Hypervisor)**를 통해 물리 리소스를 추상화하여, **여러 개의 독립된 운영체제(OS)**를 실행하는 기술입니다[cite: 2, 3, 4].
* [cite_start]**특징:** 호스트와 게스트 OS가 완전히 분리되어 보안성이 높지만 [cite: 5][cite_start], 독립된 커널을 모두 실행해야 하므로 자원 소모가 크고 무겁습니다[cite: 7].

### [cite_start]2) JVM (Java Virtual Machine, 자바 가상 머신) [cite: 9]
* [cite_start]**개념:** 자바 프로그램이 운영체제 종류에 구애받지 않고 동일하게 실행되도록 돕는 소프트웨어 수준의 가상 머신입니다[cite: 10, 11].
* [cite_start]**특징:** 컴파일된 **Bytecode**를 각 OS에 맞는 기계어로 변환하며 ("Write Once, Run Anywhere") [cite: 12][cite_start], **가비지 컬렉터(GC)**를 통해 메모리를 자동 관리합니다[cite: 16].

### [cite_start]3) WSL2 (Windows Subsystem for Linux 2) [cite: 18]
* [cite_start]**개념:** 윈도우 환경에서 경량화된 가상화 기술을 사용해 **실제 리눅스 커널**을 직접 구동하는 마이크로소프트의 기술입니다[cite: 19, 20].
* [cite_start]**특징:** WSL1 대비 파일 시스템 성능이 압도적으로 빠르며 [cite: 23][cite_start], 필요할 때만 메모리를 동적으로 할당하여 일반 VM보다 훨씬 가볍고 효율적입니다[cite: 25].

---

## 📊 4. 핵심 기술 비교표

| 구분 | [cite_start]VM (가상 머신) [cite: 27] | [cite_start]JVM (자바 가상 머신) [cite: 27] | [cite_start]WSL2 (리눅스 하위 시스템) [cite: 27] |
| :--- | :--- | :--- | :--- |
| **목적** | [cite_start]하드웨어 전체 가상화 [cite: 27] | [cite_start]소프트웨어 실행 환경 가상화 [cite: 27] | [cite_start]윈도우 내 리눅스 환경 구축 [cite: 27] |
| **핵심 요소** | [cite_start]하이퍼바이저 (Hyper-V 등) [cite: 27] | [cite_start]인터프리터 & JIT 컴파일러 [cite: 27] | [cite_start]실제 리눅스 커널 [cite: 27] |
| **장점** | [cite_start]강력한 보안 및 시스템 격리 [cite: 27] | [cite_start]OS에 상관없는 코드 실행 [cite: 27] | [cite_start]윈도우-리눅스 간의 강력한 협업 [cite: 27] |

---

## 🚀 5. 실습 워크플로우 (Git & GitHub)
수업 시간에 실습한 소스코드 및 파일 관리 흐름입니다.

```mermaid
graph LR
    A[Local Code / PDF] --> B(Git 버전 관리)
    B --> C(SourceTree GUI 활용)
    C --> D[GitHub 원격 저장소 업로드]