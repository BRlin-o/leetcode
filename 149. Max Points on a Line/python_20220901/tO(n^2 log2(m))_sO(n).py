class Solution:
    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a%b)
    
    def maxPoints(self, points):
        if len(points)<=2:
            return len(points)
        Nf_maxPointLine = 0
        for point_index in range(len(points)):
            if Nf_maxPointLine > len(points)/2 or Nf_maxPointLine > (len(points)-point_index):
                break
            line = {}
            for p2_index in range(point_index+1, len(points)):
                ## y = m*x + b 
                ## m = a1/a2
                ### => y*a2-x*a1 = b
                a1=(points[p2_index][1]-points[point_index][1])
                a2=(points[p2_index][0]-points[point_index][0])
                sym = ""
                if a1 == 0:
                    a2 = 1
                elif a2 == 0:
                    a1 = 1
                else:
                    if a1*a2>=0:
                        sym = "-"
                    gcdA = self.gcd(abs(a1), abs(a2)) if abs(a1) > abs(a2) else self.gcd(abs(a2), abs(a1))
                    a1 = abs(a1//gcdA)
                    a2 = abs(a2//gcdA)

                ## 每個round以一點為主來計算，不需考慮平面位移
                # b = points[point_index][1]*a2-points[point_index][0]*a1
                # l = "({}{:.0f}/{:.0f}, {:.0f})".format(sym, a1, a2, b)
                l = "{}{:.0f}/{:.0f}".format(sym, a1, a2)
                if l in line:
                    line[l]+=1
                else:
                    line[l]=2
                # print(l, line[l])
            for _, count in line.items():
                Nf_maxPointLine = max(Nf_maxPointLine, count)

        return Nf_maxPointLine