<h2><a href="https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/">1836. Remove Duplicates From an Unsorted Linked List</a></h2>
<h3>Medium</h3>
<hr>
<div>
<p>Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that have any of those values.</p>
<p>Return the linked list after the deletions.</p>
</div>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list.jpg">
<pre><strong>Input:</strong> head = [1,2,3,2]
<strong>Output:</strong> [1,3]
<strong>Explanation:</strong> 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3].
</pre>
<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list-1.jpg">
<pre><strong>Input:</strong> head = [2,1,1,2]
<strong>Output:</strong> []
<strong>Explanation:</strong> 2 and 1 both appear twice. All the elements should be deleted.
</pre>
<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list-2.jpg">
<pre><strong>Input:</strong> head = [3,2,2,1,3,2,4]
<strong>Output:</strong> [1,4]
<strong>Explanation:</strong> 3 appears twice and 2 appears three times. After deleting all 3's and 2's, we are left with [1,4].
</pre>
<p><strong>Constraints:</strong></p>
<ul>
<li>The number of nodes in the list is in the range [1, 10<sup>5</sup>]</li>
<li>1 <= Node.val <= 10<sup>5</sup></li>
</ul>
