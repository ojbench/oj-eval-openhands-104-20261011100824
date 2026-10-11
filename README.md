# Problem 104 - 采购

**ACMOJ Problem ID**: 1028

## Table of Contents

- [Problem 104 - 采购](#problem-104-采购)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1028. 采购** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/104/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

skytim是伟大帝国UDF的首脑。作为一国的领袖，skytim很早就认识到一国的交通对经济建设的重要性。于是他要求UDF国内的建筑排成`m*n`的网络，道路建设在建筑的上方，并且每条道路都连接着两个有公共边的建筑。如下图所示：

![](http://acm.sjtu.edu.cn/onlinejudge/pic/1515/UDF.jpg)

这天是UDF国建国110周年纪念日，skytim正在主持盛大的阅兵式。随着“同志们好！”“首长好！”的声响此起彼伏，skytim的手机突然响了，是他的夫人Cyning打来的。

“skytim你早饭煮烂了，快给我回来！”

“啊？我还在阅兵呢！”

“我不管你现在在哪里，现在马上给我回来！”

“嗯，我现在马上回去！”

“回来记得顺路帮我买一把油纸伞。我要撑着它走过那条雨巷。好想知道成为戴望舒笔下那个丁香一样的结着愁怨的姑娘是一种怎样的体验。”

“行行行，随你。”

为了及时完成夫人的任务，skytim希望能够走一条最短的经过伞店的路径回家。但遗憾的是有些建筑正在施工，和它连着的道路都不能走。好在skytim早就对自己国家的地图烂熟于心，请你协助他找到最短的路径。

### Input Format

输入第一行有两个整数`n,m`，表示地图的规模。

接下来`m`行每行`n`个数字，表示该建筑的状态。其中：

- 0表示普通建筑，可以经过。
- 1表示正在施工中的建筑，不可以经过。
- 2表示skytim阅兵的位置。
- 3表示skytim和Cyning的家。
- 4表示伞店。

### Output Format

输出一个整数，表示skytim最少需要移动的距离。

### Samples

#### Sample 1

**Input:**
```
8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0
```

**Output:**
```
11
```

### Data Constraints

对于$40\\%$的数据，$1 \le n,m \le 10$;

对于$100\\%$的数据，$1 \le n,m \le 1000$.

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 512 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/104/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
