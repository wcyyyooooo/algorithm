from collections import deque
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for token in tokens:
            if token == '*':
                a, b = st[-1], st[-2]
                st.pop(), st.pop()
                st.append(a * b)
            elif token == '+':
                a, b = st[-1], st[-2]
                st.pop(), st.pop()
                st.append(a + b)
            elif token == '-':
                a, b = st[-1], st[-2]
                st.pop(), st.pop()
                st.append(b - a)
            elif token == '/':
                a, b = st[-1], st[-2]
                st.pop(), st.pop()
                st.append(int(b / a))
            else:
                st.append(int(token))
        return st[0]
class Solution:
    def clumsy(self, n: int) -> int:
        op = ['*', '//', '+', '-']
        exp = ""
        j = 0
        for i in range(n, 0, -1):
            exp += str(i)
            exp += op[j % 4]
            j += 1
        if(exp[-1] == '/'):exp = exp[0:-2]
        else:exp = exp[0:-1]
        return int(eval(exp))
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        cnt = []
        for i in range(len(expression)):
            if(expression[i] == ')'):
                path = []
                while(cnt[-1] != '('):
                    path.append(cnt[-1])
                    cnt.pop()
                cnt.pop()
                mask = True if path[0] == 't' else False
                op = cnt[-1]
                cnt.pop()
                if op == '!': mask = mask ^ True
                for p in path[1:]:
                    if op == '|':
                        mask = (True if p == 't' else False) | mask
                    elif op == '&':
                        mask = (True if p == 't' else False) & mask
                cnt.append('f' if mask == False else 't')
            else:
                if expression[i] == ',': continue
                else: cnt.append(expression[i])
        return True if cnt[0] == 't' else False
    
class TextEditor:

    def __init__(self):
        self.st1 = []
        self.st2 = []

    def addText(self, text: str) -> None:
        self.st1 += list(text)

    def deleteText(self, k: int) -> int:
        l = max(0, len(self.st1) - k)
        le = len(self.st1) - l
        self.st1 = self.st1[0:l]
        return le
    def cursorLeft(self, k: int) -> str:
        while len(self.st1) and k:
            self.st2.append(self.st1[-1])
            self.st1.pop()
            k -= 1
        return ''.join(self.st1[len(self.st1) - min(10, len(self.st1)) : ])

    def cursorRight(self, k: int) -> str:
        while len(self.st2) and k:
            self.st1.append(self.st2[-1])
            self.st2.pop()
            k -= 1
        return ''.join(self.st1[len(self.st1) - min(10, len(self.st1)) : ])
class RecentCounter:

    def __init__(self):
        self.que = deque()

    def ping(self, t: int) -> int:
        last_t = t - 3000
        self.que.append(t)
        while self.que[0] < last_t:
            self.que.popleft()
        return len(self.que)