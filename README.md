# LeetCode Solutions

# History
## 2022/09/02
- [239. Sliding Window Maximum]
  - 透過容器特性deQue，front最大值 and back最小值，當前windows最大值取front即可
  - 如果一個點i值小於一個點j值，且i < j則該點值接下來都不會為最大值，因此可以將該點值移除
    - 代碼中算法倒續這個概念，每加入一個點時，將設該點為j，並透過deQue特性設back為i，不斷檢測將back值移除，直到back值大於j點值
  - 因每個windows都會有一個解，因此我們可以知道在i>=k-1時會有一個解
  - 如果當前deQue的front值小於等於i-k，故該值不屬於當前windows範圍，因此將該值移除

## 2022/09/01
- [149. Max Points on a Line]
  - 依序陣列以一點為中心，枚舉與其他點的斜率，則可計算該線段所擁有之點個數，後更新目前最大值。
  - 原本一條線為y=ax+b，但因為每次枚舉都有一點為中心，可假設為0, 0，故不需考慮b
  - 斜率浮點數不為精準，故用分數經gcd以及map特性，來累計該縣段的點個數
  - 小技巧
    - 當前計算出的最大點個數，如果大於所有點總數的一半，或者大於後面的點個數量，故該線以為max points line，則不需再計算，直接回傳即可

## 2022/04/21
- [704. Binary Search]: [30ms, 27.5MB](https://leetcode.com/submissions/detail/684655675/)

[704. Binary Search]: https://leetcode.com/problems/binary-search/