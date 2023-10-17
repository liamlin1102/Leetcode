#這方法是用數學來存其餘最小值
class MinStack:

    def __init__(self):
        self.st=[] #stack
        self.min=None #min element

    def push(self, val: int) -> None:
        if len(self.st)==0:
            self.st.append(val)
            self.min=val
        else:
            if val>=self.min:
                self.st.append(val)
            else:
                #如果最小值比較小，那存新最小值*2(怕變負的)-原先最小值加進去
                self.st.append(2*val-self.min)
                self.min=val
                
    def pop(self) -> None:
        x=self.st.pop()
        #檢查是否最小值比較大，因為只有我們定義的值會比最小值小，所以還原這邊的2*self.min(當初的val)-(2*val-self.min(當初的val)) 
        if x<self.min:
            self.min=2*self.min-x
    
    def top(self) -> int:
        x=self.st[-1]
        if x>=self.min:
            return x
        return self.min

    def getMin(self) -> int:
        return self.min