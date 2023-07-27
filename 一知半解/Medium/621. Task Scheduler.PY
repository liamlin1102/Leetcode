# 這題很難，要先理解，如果我們要符合條件完成任務，把出現最多次的當作起點並且以休息的次數當中間的空格，並且將其他逐一插入
# 此時會有兩種可能，我跑完了需要的空格，塞滿了任務，以及我跑完了需要的空格但沒塞滿任務，下面詳解
import heapq
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # 如果沒有休息時間，那當然回傳原來長度
        if not n :return len(tasks)
        dic={}
        # 數次數
        for task in tasks:
            if not task in dic:
                dic[task] =0
            dic[task]+=1
        pq = []
        heapq.heapify(pq)
        # 要製作max priority queue，所以把數字轉成負數
        for value in dic.values():
            heapq.heappush(pq,-value)
        # 長度
        count = 0
        # 放把所有任務取出來的暫存list
        tmps=[]
        # 當還有東西，代表任務沒被消化完畢
        while pq:
            # 這邊紀錄完成的任務，有可能已經不需要塞空缺(最後一次)，因此也要同步紀錄
            work = 0
            # 最多就是跑一次修休息時間的任務超過得之後跑以免溢出
            for i in range(n+1):
                # 當然如果沒東西那就要停下來，剩下補休息或是最後一次
                if not pq:
                    break
                # 把找來的heap元素加入list裡
                tmp = heapq.heappop(pq)
                tmps.append(tmp)
                # 紀錄工作時間，以免最後一次不補休息不知道時間
                work+=1
            # 跑裡面的數字啦 把所有次數+1(因為我們做max priority queue把工作次數帶負號進去)，之後加回去max priority queue裡面，讓下一個迴圈幹活
            for i in tmps:
                if i+1<0:               
                    heapq.heappush(pq,i+1)
            # 如果發現還有東西代表我們工作還沒結束，那不管這次工作幾次，都要把間隔捕到滿休息時間以免違反題目
            if pq:
                #n+1的原因是因為，間隔為0的兩個項目，實際差了ｎ＋１個，就跟小時候數路燈要補１ 
                count+=(n+1)
            # 發現沒東西了，代表完工了，加這次的工作時間
            elif not pq:
                count+=work    
            # 清楚list以免下次重複計算
            tmps.clear()
        return count 
