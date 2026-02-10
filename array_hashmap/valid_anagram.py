class Solution:
    def isAnagram(self,s:str,t:str)->bool:
        if(len(s)!=len(t)):
            return False
        
        counts,countt={},{}
        
        for i in range(len(s)):
            counts[s[i]]=1+counts.get(s[i],0)
            countt[t[i]]=1+countt.get(t[i],0)
            
        return counts==countt
        
        
        
        # taking input
        
s=input("Enter the first string:")
t=input("Enter the second string:")
sol=Solution()
result=sol.isAnagram(s,t)
if result:
    print("The strings are anagrams")
else:
    print("The strings are not anagrams")
