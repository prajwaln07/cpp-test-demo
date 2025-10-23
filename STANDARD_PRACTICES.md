# Standard Test Generation Practices

## 🎯 Purpose
This document defines the standard practices for generating unit tests from GitHub Pull Requests.

---

## 📋 Process Overview

### When You Provide a PR Link:

1. **I fetch** the PR and analyze changed files
2. **I read** `TEST_FOLDER_CONFIG.md` to understand your folder mapping rules
3. **I apply** the mapping rules to determine where tests should go
4. **I generate** comprehensive test files following your structure
5. **I create** necessary directories automatically

---

## 🗂️ How It Works

### Step 1: PR Analysis
- Fetch all changed `.cpp` files from the PR
- Exclude existing test files (`*_test.cpp`)

### Step 2: Fetch Configuration
- Automatically read `TEST_FOLDER_CONFIG.md`
- Parse your folder mapping rules
- Understand your directory structure

### Step 3: Apply Mapping
- For each changed file, match it to your mapping rules
- Determine the correct test location based on your config
- Example:
  - File: `geometry/Circle.cpp`
  - Config says: `geometry/*.cpp` → `tests/geometry/*_test.cpp`
  - Result: Create `tests/geometry/Circle_test.cpp`

### Step 4: Generate Tests
- Create test directory if needed
- Generate comprehensive test file
- Include proper relative paths
- Follow Google Test framework

---

## 📝 Test File Structure

### Every Test Includes:
- ✅ Constructor tests
- ✅ Method tests (all public methods)
- ✅ Edge case tests
- ✅ Exception handling tests
- ✅ Integration tests
- ✅ 50-100+ test cases per file

### Test Naming: `<Function>_<Scenario>_<ExpectedResult>`
Examples:
- `Add_PositiveNumbers_ReturnsSum`
- `Divide_ByZero_ThrowsException`
- `GetArea_RadiusFive_ReturnsCorrectValue`

---

## 🔄 Automated Workflow

```
You: "Generate tests for PR #42"

System:
  1. ✅ Fetch PR #42 from GitHub
  2. ✅ Get list of changed .cpp files
  3. ✅ Read TEST_FOLDER_CONFIG.md (your rules)
  4. ✅ Match each file to mapping rules
  5. ✅ Create test directories
  6. ✅ Generate test files in correct locations
  7. ✅ Done!

Result: Tests created following YOUR folder structure
```

---

## 📊 Example

### Your Config Says:
```
geometry/*.cpp → tests/geometry/*_test.cpp
```

### PR Changes:
```
- geometry/Circle.cpp (modified)
- geometry/Triangle.cpp (added)
```

### System Automatically:
```
1. Reads your config
2. Sees: geometry/*.cpp maps to tests/geometry/
3. Creates:
   ✅ tests/geometry/Circle_test.cpp
   ✅ tests/geometry/Triangle_test.cpp
4. Both with comprehensive test suites
```

---

## ⚙️ Customization

### To Change Folder Structure:
1. Update `TEST_FOLDER_CONFIG.md` with your new mappings
2. That's it! System will follow new rules automatically

### No Code Changes Needed:
- I read your config file every time
- Your rules are always respected
- Easy to maintain and update

---

## 🎯 Key Benefits

✅ **You Control**: Define folder structure in config  
✅ **I Fetch**: Automatically read your rules  
✅ **Automatic**: Apply rules to PR files  
✅ **Consistent**: Always follows your structure  
✅ **Easy**: Just update config file to change rules  

---

## 📚 Files

- **TEST_FOLDER_CONFIG.md**: Your folder mapping rules (you maintain)
- **STANDARD_PRACTICES.md**: This file (general practices)
- **Auto-fetched**: System reads these automatically when generating tests

---

**Framework**: Google Test  
**Language**: C++11  
**Coverage**: 100% public methods  
**Automation**: Complete
