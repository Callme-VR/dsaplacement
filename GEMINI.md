# ♊ GEMINI.md - Project Mandates

This file provides foundational instructions for AI agents interacting with the **DSAPlacement** repository. These mandates take precedence over general workflows.

---

## 🚀 Project Mission
To provide high-quality, optimized, and readable solutions for Data Structures and Algorithms (DSA) problems to aid in interview preparation and competitive programming.

---

## 🛠️ Technical Mandates

### 1. Language & Style
- **C++**: Use modern C++ standards (C++17/20). Leverage STL (`vector`, `unordered_map`, `algorithm`) effectively. Ensure `main()` includes basic test cases or allows for user input.
- **Python**: Follow PEP 8 guidelines. Use type hints where appropriate. Favor readability and built-in functions over manual loops where efficient.
- **Naming**: Use camelCase for C++ functions (or snake_case if following LeetCode style) and snake_case for Python.

### 2. Efficiency Standards
- **Big-O Analysis**: Every solution must aim for optimal time and space complexity. Avoid $O(n^2)$ solutions if $O(n \log n)$ or $O(n)$ is possible.
- **Memory**: Prioritize in-place modifications for Two Pointer problems to maintain $O(1)$ extra space.

### 3. Documentation
- When adding a new problem:
  - Place it in the appropriate category folder.
  - Update the local `README.md` in that folder with the new problem entry.
  - Ensure the solution contains a brief comment explaining the logic if the algorithm is non-trivial.

---

## 📂 Structural Integrity
- **No Binary Bloat**: Never commit `.exe` or other compiled binaries. Use `.gitignore` to exclude them.
- **Consistent Structure**: Maintain the current categorization (e.g., `slidingWindow`, `two_pointer`). Do not create redundant top-level folders without clear justification.

---

## 🤖 AI Interaction Guidelines
- **Research First**: Before proposing a fix or a new solution, analyze existing patterns in the relevant folder.
- **Explanation**: When explaining solutions, focus on the "Why" and the "Pattern" (e.g., "This uses a sliding window because we need to find a contiguous subarray...").
- **Verification**: If requested to add a problem, always verify it with at least 2-3 test cases (edge cases included).

---

*This document ensures consistency and quality across the DSAPlacement codebase.*
