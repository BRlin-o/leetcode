# LeetCode Solutions

# History
## 2022/09/02
- [239. Sliding Window Maximum]: Best Accept[328ms(88.75%), 134.6MB(92.32%)]
  - 透過容器特性deQue，front最大值 and back最小值，當前windows最大值取front即可
  - 如果一個點i值小於一個點j值，且i < j則該點值接下來都不會為最大值，因此可以將該點值移除
    - 代碼中算法倒續這個概念，每加入一個點時，將設該點為j，並透過deQue特性設back為i，不斷檢測將back值移除，直到back值大於j點值
  - 因每個windows都會有一個解，因此我們可以知道在i>=k-1時會有一個解
  - 如果當前deQue的front值小於等於i-k，故該值不屬於當前windows範圍，因此將該值移除

## 2022/09/01
- [149. Max Points on a Line]: Best Accept[188ms(51.32%), 13.4MB(80.95%)]
  - 依序陣列以一點為中心，枚舉與其他點的斜率，則可計算該線段所擁有之點個數，後更新目前最大值。
  - 原本一條線為y=ax+b，但因為每次枚舉都有一點為中心，可假設為0, 0，故不需考慮b
  - 斜率浮點數不為精準，故用分數經gcd以及map特性，來累計該縣段的點個數
  - 小技巧
    - 當前計算出的最大點個數，如果大於所有點總數的一半，或者大於後面的點個數量，故該線以為max points line，則不需再計算，直接回傳即可

## 2022/04/21
- [704. Binary Search]: Best Accept[30ms, 27.5MB]

## 2021/08/02
- [827. Making A Large Island]: Best Accept[416ms(98.59%), 104.2MB(81.41%)]

## 2021/07/05
- [1220. Count Vowels Permutation]: Best Accept[4ms(79.32%), 6MB(73.96%)]

## 2020/03/23
- [4. Median of Two Sorted Arrays]
  - [32ms(97.54%), 7.7MB(100%)]

[704. Binary Search]: https://leetcode.com/problems/binary-search/
[149. Max Points on a Line]: https://leetcode.com/problems/max-points-on-a-line/
[239. Sliding Window Maximum]: https://leetcode.com/problems/sliding-window-maximum/
[827. Making A Large Island]: https://leetcode.com/problems/making-a-large-island/
[1220. Count Vowels Permutation]: https://leetcode.com/problems/count-vowels-permutation/
[4. Median of Two Sorted Arrays]: https://leetcode.com/problems/median-of-two-sorted-arrays/