import re
from classes import BaseAnalyzer

class SentenceAnalyzer(BaseAnalyzer):
    """Analyze sentence counts and lengths."""
    def analyze(self):
        sentences = re.split(r'(?<=[.!?]) +', self.text)
        total = len(sentences)
        types = {'declarative': 0, 'interrogative': 0, 'imperative': 0}
        lengths = []
        for s in sentences:
            if s.endswith('?'):
                types['interrogative'] += 1
            elif s.endswith('!'):
                types['imperative'] += 1
            else:
                types['declarative'] += 1
            #lengths.append(len(re.sub(r'[^A-Za-z ]', '', s).replace(' ', '')))
            words = re.findall(r'[A-Za-zА-Яа-я]+', s)
            for word in words:
                lengths.append(len(word))
        avg_len = sum(lengths)/total if total else 0
        return total, types, avg_len

class WordAnalyzer(BaseAnalyzer):
    """Analyze words: lengths, emoticons, patterns."""
    EMOJI_PATTERN = re.compile(r"^[;:]-*[()\[\]]+$")
    CONSONANTS = set("bcdfghjklmnpqrstvwxyz")

    def analyze(self):
        words = re.findall(r"\b\w+\b", self.text)
        total_words = len(words)
        lengths = [len(w) for w in words]
        avg_word_len = sum(lengths)/total_words if total_words else 0
        emoticons = [w for w in re.findall(r"[;:]-*[()\[\]]+", self.text) if self.EMOJI_PATTERN.match(w)]
        return words, avg_word_len, len(emoticons), emoticons

    def words_starting_lower_consonant(self):
        return [w for w in re.findall(r"\b[a-z]\w*\b", self.text) if w[0] in self.CONSONANTS]

    def words_followed_by_comma(self):
        return re.findall(r"\b\w+\b(?=,)", self.text)

    def longest_ending_with_y(self):
        ys = [w for w in re.findall(r"\b\w+\b", self.text) if w.lower().endswith('y')]
        return max(ys, key=len) if ys else None
