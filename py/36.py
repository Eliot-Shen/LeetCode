class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        record = {}
        # for k in range(1,10)
        #     for i in range(1+3*(k-1),4+3*(k-1)):
        #         for j in range(1+3*(k-1),4+3*(k-1)):
        #             record[[k,i,j]] = board[i][j]
        #record 9*9
        # for i in range(1,10):
        #     for j in range(1,10):
        #         record[[i,j]] = board[i][j]
        # for k in range(1,10)
        #     if len(set(record[[k,a]] for a in range(1,10))) < 9:
        #         return False
        #     if len(set(record[[a,k]] for a in range(1,10))) < 9:
        #         return False
        #     if len(set(record))
        row = [[0] * 9 for _ in range(9)]
        col = [[0] * 9 for _ in range(9)]
        block = [[0] * 9 for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j]) - 1
                    b = (i // 3) * 3 + j // 3                       #判断所处块位置,注意下标范围0-8
                    if row[i][num] or col[j][num] or block[b][num]: #如果该数已经存在,返回false
                        return False
                    row[i][num] = col[j][num] = block[b][num] = 1
        return True

        
