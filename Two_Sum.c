#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int key;
	int value;
} HashData;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* result = (int *)malloc((* returnSize) * sizeof(int));
	if(result == NULL) {
		fprintf(stderr, "Memory Allocation Failed\n");
		return NULL;
	}

	HashData* hashTable = (HashData *)malloc(numsSize * sizeof(hashTable));
	if (hashTable == NULL) {
		fprintf(stderr, "Memory Allocation Failed\n");
		free(result);
		return NULL;
	}

	int hashCount = 0;
	for(int i=0; i<numsSize; i++) {
		int remaining = target - nums[i];
		for(int j=0; j<hashCount; j++) {
			if(hashTable[j].key == remaining) {
				result[0] = hashTable[j].value;
				result[1] = i;
				free(hashTable);
				return result;
			}
		}

		hashCount++;
		hashTable[i].value = i;
		hashTable[i].key = nums[i];
	}

	free(result);
	free(hashTable);

	return NULL;
}

int main() {
	int nums[] = {3,2,4};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 6;
	int returnSize = 2;

	int* res = twoSum(nums, numsSize, target, &returnSize);

	printf("[%d %d]\n", res[0], res[1]);

	return 0;
}
