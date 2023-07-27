#這題超難 不知道怎麼做.....
# 看了一些東西還是了解一下
# 簡單說這題要反過來做，與其去想怎麼從中間流出去，不如從邊界回推回來 那些點可以流向邊界
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # 把兩個邊長做出來
        widthx = len(heights[0]);widthy =  len(heights)
        # 把P 跟 a 的洋流碰到的點找一個存放點，依樣順便當重複的
        p_visited = set()
        a_visited = set()
        # 如果長度只有1 那就傳0,0回來
        if widthy==1 and widthx ==1:return [[0,0]]
        def dfs(x,y,prev_height,visited):
            # 超過邊界或是已經走過的點或是目前的點比上一個點矮，代表水流不過來
            if y<0 or x<0 or y>widthy-1 or x > widthx-1 or (y,x) in visited or heights[y][x]<prev_height :
                return 
            
            cur_height= heights[y][x]
            # 把目前的點加進去，由於是set不存在把重複地點加入的問題
            visited.add((y,x))
            # 左
            dfs(x,y-1,cur_height,visited)
            # 上
            dfs(x-1,y,cur_height,visited)
            # 右
            dfs(x,y+1,cur_height,visited)
            # 下
            dfs(x+1,y,cur_height,visited)
            return
        # 從四邊收進來 

        for col in range(widthx):
            # 最上面那row          
            dfs(col,0,heights[0][col],p_visited)         
            # 最下面那row
            dfs(col,widthy-1,heights[widthy-1][col],a_visited)       

        for row in range(widthy):
            # 最左邊那col
            dfs(0,row,heights[row][0],p_visited)
            # 最右邊那col
            dfs(widthx-1,row,heights[row][widthx-1],a_visited) 
        # 算交會處
        return list(p_visited & a_visited)