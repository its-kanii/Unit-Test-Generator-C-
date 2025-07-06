# 🧪 AI-Powered C++ Unit Test Generator

This project demonstrates an AI-driven unit test generator for a C++ application using a local large language model (LLM), specifically Ollama. It automates the creation, refinement, and validation of unit tests based on the source code.

---

## 📁 Project Structure

```
.
├── .github/                # (Optional) GitHub workflows or metadata
├── build/                  # Compiled binaries and coverage reports
├── orgChartApi/            # C++ application source code (Drogon-based)
├── tests/                  # Auto-generated test cases (Google Test)
├── generate_tests          # Python script to generate unit tests via LLM
├── strict.yaml             # YAML prompt with LLM instructions
└── README.md               # This file
```

---

## ⚙️ Tech Stack

- **C++** with **Drogon** Web Framework
- **Google Test** (gtest) for unit testing
- **Ollama LLM** (self-hosted) for test generation
- **LCOV & genhtml** for code coverage reports
- **JSONCPP** and PostgreSQL as dependencies
- **YAML** for strict prompting

---

## 🧠 How It Works

1. **Generate Initial Tests:**
   Run the Python script `generate_tests` with the `.cc` files from `orgChartApi/`.
   It uses a YAML prompt (`strict.yaml`) to instruct the LLM (like LLaMA via Ollama) to generate tests.

2. **Refinement:**
   The script re-prompts the LLM to:
   - Eliminate duplicate tests
   - Add missing includes
   - Structure tests cleanly using `TEST_F` and `ASSERT`

3. **Build & Debug:**
   - Uses `cmake` and `make` to build the project.
   - Failing builds are re-sent to LLM for patching.

4. **Code Coverage:**
   ```bash
   lcov --capture --directory . --output-file coverage.info
   genhtml coverage.info --output-directory out
   xdg-open out/index.html
   ```

---

## 📌 YAML Prompt Example (`strict.yaml`)

```yaml
instructions:
  - Read the given C++ source
  - Generate unit tests using Google Test
  - Avoid duplicate tests
  - Include necessary headers
  - Ensure test cases are valid and cover edge cases
```

---

## 📊 Final Output Includes

- ✅ Full test coverage (see `out/index.html`)
- ✅ Clean test files in `tests/`
- ✅ Build-ready project with CI support
- ✅ Reproducible pipeline with `generate_tests`

---

## 👤 Author

> Kanimozhi ([@its-kanii](https://github.com/its-kanii))  
> C++ | Drogon | AI | Ollama | Google Test  

---

## 📄 License

This project is licensed under the MIT License.
