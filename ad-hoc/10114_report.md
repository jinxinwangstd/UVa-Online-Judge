## Problem description

Given a car loan, its down payment and the depreciation of car in every month, figure out in which month the value of car is greater than the loan amount

## Algorithm analysis

Simulate the process of paying loan and depreciating in every month, check in which month it satisfies our condition.
Suppose the maximum month is n, so the time complexity is O(n).

## Knowledge base

1. Concept related to loan:
   Down payment: 首付
   Loan: 贷款
   Monthly payment: Loan amount / paying months
2. 当计算涉及到浮点数时，应使用epsilon来判断大小及相等关系