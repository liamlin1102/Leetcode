# 超簡單，用queue時做出stack，兩個唯一的不同在於 FIFO跟LIFO，以及top/peek的時候看哪邊
class MyStack:
    from collections import deque
    def __init__(self):
        self.queue = deque([])
        
    def push(self, x: int) -> None:
        # 我們這邊把右側當進入口，數字往右變多，可以理解成，數字從右往左塞
        self.queue.append(x)
    def pop(self) -> int:
        # 那這樣就是要先取最右邊，因為stack是LIFO，最右邊肯定是最新的
        return self.queue.pop()

    def top(self) -> int:
        # top也看最右邊最新的
        return self.queue[-1]

    def empty(self) -> bool:
        # BJ4
        return len(self.queue)==0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()