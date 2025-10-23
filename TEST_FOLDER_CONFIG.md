# Test Generation Configuration

## 📋 Overview
This file defines the mapping rules for where test files should be created based on source file locations in Pull Requests.

---

## 🎯 Folder Mapping Rules

### Format
```
Source Location → Test Location
```

### Mapping Table

| Source File Path | Test File Path | Notes |
|------------------|----------------|-------|
| `geometry/*.cpp` | `tests/geometry/*_test.cpp` | Geometry module tests |
| `maths/*.cpp` | `tests/maths/*_test.cpp` | Math utilities tests |
| `*.cpp` (root) | `tests/*_test.cpp` | Root level files |
| `<folder>/*.cpp` | `tests/<folder>/*_test.cpp` | Generic rule for any folder |

---

## 📝 Test Naming Convention

**Pattern**: `<SourceFileName>_test.cpp`

**Examples**:
- `Circle.cpp` → `Circle_test.cpp`
- `calculator.cpp` → `calculator_test.cpp`
- `random.cpp` → `random_test.cpp`

---

## 🗂️ Directory Structure

### Current Structure
```
cpp-test-demo/
├── geometry/           → tests/geometry/
│   ├── Circle.cpp     → tests/geometry/Circle_test.cpp
│   └── Triangle.cpp   → tests/geometry/Triangle_test.cpp
├── maths/             → tests/maths/
│   ├── Maths.cpp      → tests/maths/Maths_test.cpp
│   └── random.cpp     → tests/maths/random_test.cpp
├── calculator.cpp     → tests/calculator_test.cpp
├── circle.cpp         → tests/circle_test.cpp
└── tests/
    ├── geometry/      (auto-created)
    └── maths/         (auto-created)
```

---

## 🔧 Customization

### To Add New Folder Mapping:
1. Add a row to the mapping table above
2. Follow the pattern: `<source_path>` → `tests/<source_path>`
3. Tests will be auto-generated in the specified location

### Example:
```
New folder: utils/
Source: utils/Helper.cpp
Test: tests/utils/Helper_test.cpp
```

Simply update this file, and the system will follow the new rules!

---

## 📚 Related Files

- **Standard Practices**: See general test generation standards
- **This Config**: Defines folder-specific mappings
- **Auto-Fetched**: System reads this file automatically

---

**Last Updated**: October 22, 2025  
**Version**: 1.0
