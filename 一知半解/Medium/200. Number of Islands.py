# 解題思路，往另一個角度想，要怎麼知道小島是獨立個體，簡單，遇到小島的時候把小島變成海
# 並且往四個方向檢查，如果都是海代表我們把這個小島填完海了，如果還有任何一個地方是陸地就在往該點四個方向填陸
# 並在結束的時候把小島數量+1
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # 一開始當然0個
        islands = 0
        # 跑回圈先跑row
        for first in range(len(grid)):
            # 再跑column
            for second in  range(len(grid[first])):
                # 如果是1的話(代表碰到陸地了)，那我們就進去找他四周只要找完四周那這就是一塊獨立的土地了
                if grid[first][second] == "1":
                    # 領土+1
                    islands+=1
                    # 跑DFS下去把四周的陸地填成海，以免之後碰到重複的
                    self.dfs(grid,first,second)
        return islands

    def dfs(self,grid,first,second):
        # 如果超過邊界就直接回頭
        if (first < 0 or second < 0 )or (first >=  len(grid) or second >= len(grid[first])):
            return
        # 如果是海回頭
        if grid[first][second] == "0":
            return
        # 把這塊陸地填成海，以免上下左右碰到重複又一職重複計算
        grid[first][second] = "0"
        # 下
        self.dfs(grid, first + 1, second)
        # 上
        self.dfs(grid, first - 1, second)
        # 右
        self.dfs(grid, first, second + 1)
        # 左
        self.dfs(grid, first, second - 1)