class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        self.count = 10
        self.flag = False
        self.n = n - self.count
        if self.n < 0:
            return self.flag
        else:
            while 1:
                self.take_turn()
                if self.n < 0:
                    return self.flag
                
    def take_turn(self):
        self.flag = not self.flag
        self.count = self.count - 1
        self.n = self.n - self.count
        return 




