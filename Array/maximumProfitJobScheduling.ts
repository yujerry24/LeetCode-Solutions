function sortFunction(a: number[], b: number[]) {
  if (a[0] === b[0]) {
    return 0;
  } else {
    return a[0] < b[0] ? -1 : 1;
  }
}
function recurse(index: number, jobs: number[][], dpArray: number[]) {}
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
  recurse(0, jobs, dp);
  return dp[startTime.length];
}
