给n个字符串，每个字符串都是排好上升的满足i+1>=i，比如aabfxyz。

从中选取任意个字符串拼接，要求拼接后仍是上升的。
返回最长的字符串的长度。

```bash
input

4
aaa
bcd
zzz
bcdef

output

11

解释：
aaa + bcdef + zzz

```