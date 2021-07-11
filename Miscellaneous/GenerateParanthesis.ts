function generateStrings(
  leftUsed: number,
  rightUsed: number,
  currentString: string,
  totalAllowed: number,
  solutions: string[]
) {
  if (leftUsed > totalAllowed) {
    return;
  }
  if (rightUsed > totalAllowed) {
    return;
  }
  if (leftUsed === rightUsed && leftUsed === totalAllowed) {
    solutions.push(currentString);
  }
  if (leftUsed - rightUsed <= -1) {
    return;
  }
  generateStrings(
    leftUsed + 1,
    rightUsed,
    currentString + "(",
    totalAllowed,
    solutions
  );
  generateStrings(
    leftUsed,
    rightUsed + 1,
    currentString + ")",
    totalAllowed,
    solutions
  );
}

function generateParenthesis(n: number): string[] {
  let solutions: string[] = [];
  generateStrings(0, 0, "", n, solutions);
  return solutions;
}
