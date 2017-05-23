// Copyright 2017 Qi Wang
// Date: 2017-05-04
const inorderTraversal = root => {
  if (root === null) return [];
  const result = inorderTraversal(root.left);
  // ... : Destructuring assignment.
  //   - https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment
  // Assume result = [1, 2], root.val = 3, inorderTraversal(root.right) =
  // [4, 5, 6]. Then we will get result = [1, 2, 3, 4, 5, 6] after the push
  // operation.
  result.push(root.val, ...inorderTraversal(root.right));
  return result;
};
