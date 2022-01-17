# C/C++、Java是向零取整（负数向上、正数向下取整），Python是向下取整。
class Solution:
	def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        rev = 0
        while x != 0:
            # INT_MIN是负数，python向下取整，因此不能写成rev < INT_MIN // 10
            if rev < INT_MIN // 10 + 1 or rev > INT_MAX // 10:
                return 0
            digit = x % 10
            # python3的取模运算在x为负数时，会返回[0,9]以内的结果，因此需要特殊判断处理
            if x < 0 and digit > 0:
                digit -= 10
            # 同理，因为向下取整，x为负数时，不能写成x //= 10
            x = (x - digit) // 10
            rev = rev * 10 + digit
    return rev