class Solution:
  def intersect(self, nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    # if len(nums1) > len(nums2):
    #   return self.intersect(nums2, nums1)
    # Constructs a map
    num_to_freq_map = {}
    for num in nums1:
      if num not in num_to_freq_map:
        num_to_freq_map.setdefault(num, 1)
      else:
        num_to_freq_map[num] = num_to_freq_map[num] + 1
    print(num_to_freq_map)
    # Loops nums2 to get the result by looking up the map
    result = []
    for num in nums2:
      if num in num_to_freq_map and num_to_freq_map[num] > 0:
        num_to_freq_map[num] = num_to_freq_map[num] - 1
        result.append(num)
    return result
