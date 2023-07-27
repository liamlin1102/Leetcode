# 這題是用stacj實作queue，一樣注意一下FIFO跟LIFO跟 選擇入口差別
class MyQueue:
    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        # 把數字從右邊加進來，代表數字是由右往左加，右邊最新
        self.stack.append(x)

    def pop(self) -> int:
        # 那queue要從最舊的地方取東西出來，那當然是最左邊
        return self.stack.pop(0)

    def peek(self) -> int:
        # queue的peek要看最前方(最早近來)的元素，選第一個
        return self.stack[0]

    def empty(self) -> bool:
        # BJ4
        return len(self.stack)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()