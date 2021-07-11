function sortFunction(a: number[], b: number[]) {
  if (a[0] === b[0]) {
    return 0;
  } else {
    return a[0] < b[0] ? -1 : 1;
  }
}

function findNext(index: number, jobs: number[][]): number {
  for (let i = index + 1; i < jobs.length; i++) {
    if (jobs[i][0] >= jobs[index][1]) {
      return i;
    }
  }
  return -1;
}
function recurse(index: number, jobs: number[][], dpArray: number[]) {
  if (index == jobs.length) {
    return 0;
  }
  if (dpArray[index] !== undefined) {
    return dpArray[index];
  }
  let nextJob = findNext(index, jobs);
  let takeProfit =
    jobs[index][2] + (nextJob === -1 ? 0 : recurse(nextJob, jobs, dpArray));
  let remainProfit = recurse(index + 1, jobs, dpArray);
  dpArray[index] = Math.max(takeProfit, remainProfit);
  return dpArray[index];
}
function jobScheduling(
  startTime: number[],
  endTime: number[],
  profit: number[]
): number {
  let jobs: number[][] = [];
  for (let i = 0; i < startTime.length; i++) {
    jobs.push([startTime[i], endTime[i], profit[i]]);
  }
  jobs.sort(sortFunction);
  console.log(jobs);
  let dp: number[] = new Array(startTime.length);
  return recurse(0, jobs, dp);
}
