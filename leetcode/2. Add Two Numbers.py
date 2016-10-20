class Solution(object):
	def addTwoNumbers(self, l1, l2, carry = 0):
		if l1 != None and l2 != None:
			sum = l1.val + l2.val + carry
			res = ListNode(sum % 10)
			res.next = self.addTwoNumbers(l1.next, l2.next, sum / 10)
			return res
		else:
			return self.addSingleNumber(l1, carry) \
				if l1 != None else self.addSingleNumber(l2, carry)

	def addSingleNumber(self, l, carry):
		if l == None:
			return ListNode(1) if carry==1 else None
		else:
			sum = l.val + carry
			res = ListNode(sum % 10)
			res.next = self.addSingleNumber(l.next, sum / 10)
			return res
