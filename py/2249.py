class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        record = []
        for i in circles:
            record.append([i[0] - i[2],i[1]])
            record.append([i[0] + i[2],i[1]])
            record.append([i[0],i[1] - i[2]])
            record.append([i[0],i[1] + i[2]])
            for j in range(i[0] - i[2] + 1,i[0] + i[2]):
                for k in range(i[1] - i[2] + 1,i[1] + i[2]):
                    record.append([j,k])
        new_li=[]
        for i in record:
            if i not in new_li:
                new_li.append(i)
        return len(new_li)
#2 
    hashmap = dict()

    for cx, cy, r in circles:
        for x in range(cx-r, cx+r+1):
            for y in range(cy-r, cy+r+1):
                if (x-cx)**2+(y-cy)**2 <= r**2 and not (x, y) in hashmap:
                    hashmap[(x, y)] = 1
    
    return len(hashmap)


                

