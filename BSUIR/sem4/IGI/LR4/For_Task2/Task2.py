# -*- coding: utf-8 -*-
"""
Lab #4: Text Analysis Program
Version: 1.0
Author: Matynkevich Evgeni
Date: 2025-05-20

Purpose:
    Read a text file, analyze with regex, compute various statistics, archive results,
    and provide a friendly CLI interface with input validation and exception handling.
"""

from classes import BaseAnalyzer
from regex_analyzers import SentenceAnalyzer, WordAnalyzer
from validators import is_valid_plate
from file_handler import read_text, write_results, archive_file


def get_input(prompt, validator=None):
    """Get validated user input."""
    while True:
        val = input(prompt)
        try:
            if validator and not validator(val):
                raise ValueError("Invalid input")
            return val
        except Exception as e:
            print(f"Error: {e}")


def main():
    while True:
        path = get_input("Enter source file path: ")
        text = read_text(path)
        sa = SentenceAnalyzer(text)
        total_s, types, avg_s_len = sa.analyze()
        wa = WordAnalyzer(text)
        words, avg_w_len, emo_count, _ = wa.analyze()
        # other tasks
        results = (
            f"Total sentences: {total_s}\n"
            f"Types: {types}\n"
            f"Avg sentence len (chars): {avg_s_len:.2f}\n"
            f"Total words: {len(words)}\n"
            f"Avg word len: {avg_w_len:.2f}\n"
            f"Emoticons: {emo_count}\n"
            f"Words start lower consonant: {wa.words_starting_lower_consonant()}\n"
            f"Words before comma: {wa.words_followed_by_comma()}\n"
            f"Longest ending 'y': {wa.longest_ending_with_y()}\n"
        )
        out = get_input("Enter result file path: ")
        write_results(out, results)
        info = archive_file(out, out + '.zip')
        print(f"Archived: {info.filename}, size: {info.file_size}")
        cont = get_input("Run again? (y/n): ", lambda x: x.lower() in ('y','n'))
        if cont.lower() == 'n':
            break

if __name__ == '__main__':
    main()
