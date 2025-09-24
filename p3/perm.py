from typing import List

def subsets_with_permutations(nums: List[int]) -> List[List[int]]:
    nums.sort()
    results = []

    # --- Step 1: generate unique subsets ---
    def backtrack_subset(start, path):
        # for each subset, generate permutations
        generate_permutations(path)
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i-1]:  # skip duplicates
                continue
            backtrack_subset(i + 1, path + [nums[i]])

    # --- Step 2: generate unique permutations ---
    def generate_permutations(subset):
        if not subset:  # empty subset
            results.append([])
            return

        used = [False] * len(subset)
        subset.sort()  # sort so permutations come in lexicographic order
        perm = []

        def backtrack_perm():
            if len(perm) == len(subset):
                results.append(perm[:])
                return
            for i in range(len(subset)):
                if used[i]:
                    continue
                if i > 0 and subset[i] == subset[i-1] and not used[i-1]:
                    continue
                used[i] = True
                perm.append(subset[i])
                backtrack_perm()
                perm.pop()
                used[i] = False

        backtrack_perm()

    backtrack_subset(0, [])

    # --- Step 3: sort results lexicographically ---
    results.sort()
    return results


# Example run
nums = [1, 2]
ans = subsets_with_permutations(nums)
for a in ans:
    print(a)
