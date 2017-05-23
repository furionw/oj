// Copyright 2017 Qi Wang
// Date: 2017-05-04
const maxDepth = root => {
  if (root === null) return 0;
  return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
};
