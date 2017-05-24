// Copyright 2017 Qi Wang
// Date: 2017-05-24
const twoSum = (nums, target) => {
  for (let i = 0; i < nums.length; ++i)
    for (let j = i + 1; j < nums.length; ++j)
      if (nums[i] + nums[j] === target)
        return [i, j];
};

// Method 2
// Date: 2017-05-04
const twoSum = (nums, target) => {
  const map = new Map();
  for (let i = 0; i < nums.length; ++i)
    if (map.has(target - nums[i])) {
      return [map.get(target - nums[i]), i];
    } else {
      map.set(nums[i], i);
    }
};

// Method 1
// Date: 2017-05-04
const twoSum = (nums, target) => {
  for (let i = 0; i < nums.length; ++i)
    for (let j = 0; j < nums.length; ++j)
      if (i !== j && target === nums[i] + nums[j])
        return [i, j];
};
