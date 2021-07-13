function recurse(
  word: string,
  existingWords: Set<string>,
  map: Map<string, number>
) {
  if (map.has(word)) {
    return map.get(word);
  }
  if (!existingWords.has(word)) {
    return 0;
  }
  let longestChain = 1;
  for (let i = 0; i < word.length; i++) {
    longestChain = Math.max(
      longestChain,
      1 +
        recurse(
          word.substr(0, i) + word.substr(i + 1, word.length),
          existingWords,
          map
        )
    );
  }
  map.set(word, longestChain);
  return longestChain;
}

function longestStrChain(words: string[]): number {
  let existingWords = new Set(words);
  words.sort();
  let dpMap = new Map();
  let max = 0;
  for (let i = 0; i < words.length; i++) {
    let value = recurse(words[i], existingWords, dpMap);
    max = Math.max(value, max);
  }
  return max;
}
