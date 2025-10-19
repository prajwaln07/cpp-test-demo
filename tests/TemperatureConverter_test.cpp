// AI-Generated Unit Tests for temprature.cpp (TemperatureConverter)
// Generated: 2025-10-19
// Framework: Google Test
// Test Coverage: celsiusToFahrenheit, fahrenheitToCelsius, celsiusToKelvin, kelvinToCelsius, nearlyEqual

#include <gtest/gtest.h>
#include <stdexcept>
#include <cmath>

// Include the class directly since it's not in a header
class TemperatureConverter {
public:
    static double celsiusToFahrenheit(double celsius) {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    static double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    static double celsiusToKelvin(double celsius) {
        return celsius + 273.15;
    }

    static double kelvinToCelsius(double kelvin) {
        if (kelvin < 0)
            throw std::invalid_argument("Kelvin cannot be negative");
        return kelvin - 273.15;
    }

    static bool nearlyEqual(double a, double b, double epsilon = 0.001) {
        return fabs(a - b) < epsilon;
    }
};

// ============================================
// Test Suite: TemperatureConverter
// ============================================

class TemperatureConverterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Common setup for all tests
        epsilon = 0.001;  // Tolerance for floating-point comparisons
    }
    
    void TearDown() override {
        // Common cleanup for all tests
    }
    
    double epsilon;
};

// ============================================
// Tests for celsiusToFahrenheit()
// ============================================

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_Zero) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(0.0), 32.0);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_BoilingPoint) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(100.0), 212.0);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_FreezingPoint) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(0.0), 32.0);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_RoomTemperature) {
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(25.0), 77.0, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_NegativeTemperature) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(-40.0), -40.0);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_BelowFreezing) {
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(-10.0), 14.0, epsilon);
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(-20.0), -4.0, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_DecimalValues) {
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(37.5), 99.5, epsilon);
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(12.5), 54.5, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_VeryHot) {
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(200.0), 392.0, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToFahrenheit_VeryCold) {
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(-273.15), -459.67, epsilon);
}

// ============================================
// Tests for fahrenheitToCelsius()
// ============================================

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_FreezingPoint) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::fahrenheitToCelsius(32.0), 0.0);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_BoilingPoint) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::fahrenheitToCelsius(212.0), 100.0);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_RoomTemperature) {
    EXPECT_NEAR(TemperatureConverter::fahrenheitToCelsius(77.0), 25.0, epsilon);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_NegativeTemperature) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::fahrenheitToCelsius(-40.0), -40.0);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_BelowFreezing) {
    EXPECT_NEAR(TemperatureConverter::fahrenheitToCelsius(14.0), -10.0, epsilon);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_BodyTemperature) {
    EXPECT_NEAR(TemperatureConverter::fahrenheitToCelsius(98.6), 37.0, 0.1);
}

TEST_F(TemperatureConverterTest, FahrenheitToCelsius_DecimalValues) {
    EXPECT_NEAR(TemperatureConverter::fahrenheitToCelsius(99.5), 37.5, epsilon);
}

// ============================================
// Tests for celsiusToKelvin()
// ============================================

TEST_F(TemperatureConverterTest, CelsiusToKelvin_AbsoluteZero) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToKelvin(-273.15), 0.0);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_Zero) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToKelvin(0.0), 273.15);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_RoomTemperature) {
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(25.0), 298.15, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_BoilingPoint) {
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(100.0), 373.15, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_NegativeTemperature) {
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(-10.0), 263.15, epsilon);
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(-50.0), 223.15, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_HighTemperature) {
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(500.0), 773.15, epsilon);
}

TEST_F(TemperatureConverterTest, CelsiusToKelvin_DecimalValues) {
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(37.5), 310.65, epsilon);
}

// ============================================
// Tests for kelvinToCelsius()
// ============================================

TEST_F(TemperatureConverterTest, KelvinToCelsius_AbsoluteZero) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::kelvinToCelsius(0.0), -273.15);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_FreezingPoint) {
    EXPECT_DOUBLE_EQ(TemperatureConverter::kelvinToCelsius(273.15), 0.0);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_RoomTemperature) {
    EXPECT_NEAR(TemperatureConverter::kelvinToCelsius(298.15), 25.0, epsilon);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_BoilingPoint) {
    EXPECT_NEAR(TemperatureConverter::kelvinToCelsius(373.15), 100.0, epsilon);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_HighTemperature) {
    EXPECT_NEAR(TemperatureConverter::kelvinToCelsius(773.15), 500.0, epsilon);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_NegativeKelvin_ThrowsException) {
    EXPECT_THROW(TemperatureConverter::kelvinToCelsius(-1.0), std::invalid_argument);
    EXPECT_THROW(TemperatureConverter::kelvinToCelsius(-10.0), std::invalid_argument);
    EXPECT_THROW(TemperatureConverter::kelvinToCelsius(-273.15), std::invalid_argument);
}

TEST_F(TemperatureConverterTest, KelvinToCelsius_DecimalValues) {
    EXPECT_NEAR(TemperatureConverter::kelvinToCelsius(310.65), 37.5, epsilon);
}

// ============================================
// Tests for nearlyEqual()
// ============================================

TEST_F(TemperatureConverterTest, NearlyEqual_ExactlyEqual) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(25.0, 25.0));
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(0.0, 0.0));
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(-10.0, -10.0));
}

TEST_F(TemperatureConverterTest, NearlyEqual_WithinDefaultEpsilon) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(25.0, 25.0009));
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(25.0, 24.9991));
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(0.0, 0.0005));
}

TEST_F(TemperatureConverterTest, NearlyEqual_BeyondDefaultEpsilon) {
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(25.0, 25.002));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(25.0, 24.997));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(0.0, 0.002));
}

TEST_F(TemperatureConverterTest, NearlyEqual_CustomEpsilon) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(25.0, 25.05, 0.1));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(25.0, 25.2, 0.1));
}

TEST_F(TemperatureConverterTest, NearlyEqual_NegativeNumbers) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(-25.0, -25.0005));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(-25.0, -25.002));
}

TEST_F(TemperatureConverterTest, NearlyEqual_VerySmallNumbers) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(0.0001, 0.0002, 0.001));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(0.0001, 0.002, 0.001));
}

TEST_F(TemperatureConverterTest, NearlyEqual_VeryLargeNumbers) {
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(1000000.0, 1000000.0005));
    EXPECT_FALSE(TemperatureConverter::nearlyEqual(1000000.0, 1000001.0));
}

// ============================================
// Conversion Round-Trip Tests
// ============================================

TEST_F(TemperatureConverterTest, RoundTrip_CelsiusToFahrenheitAndBack) {
    double celsius = 25.0;
    double fahrenheit = TemperatureConverter::celsiusToFahrenheit(celsius);
    double backToCelsius = TemperatureConverter::fahrenheitToCelsius(fahrenheit);
    
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(celsius, backToCelsius));
}

TEST_F(TemperatureConverterTest, RoundTrip_CelsiusToKelvinAndBack) {
    double celsius = 25.0;
    double kelvin = TemperatureConverter::celsiusToKelvin(celsius);
    double backToCelsius = TemperatureConverter::kelvinToCelsius(kelvin);
    
    EXPECT_TRUE(TemperatureConverter::nearlyEqual(celsius, backToCelsius));
}

TEST_F(TemperatureConverterTest, RoundTrip_MultipleTemperatures) {
    double temperatures[] = {-273.15, -100.0, -40.0, 0.0, 25.0, 37.0, 100.0, 200.0};
    
    for (double temp : temperatures) {
        // Test Celsius -> Fahrenheit -> Celsius
        double f = TemperatureConverter::celsiusToFahrenheit(temp);
        double c = TemperatureConverter::fahrenheitToCelsius(f);
        EXPECT_TRUE(TemperatureConverter::nearlyEqual(temp, c)) 
            << "Failed for temperature: " << temp;
        
        // Test Celsius -> Kelvin -> Celsius (only for valid Kelvin values)
        if (temp >= -273.15) {
            double k = TemperatureConverter::celsiusToKelvin(temp);
            double c2 = TemperatureConverter::kelvinToCelsius(k);
            EXPECT_TRUE(TemperatureConverter::nearlyEqual(temp, c2))
                << "Failed for temperature: " << temp;
        }
    }
}

// ============================================
// Special Temperature Points
// ============================================

TEST_F(TemperatureConverterTest, SpecialPoints_AbsoluteZero) {
    // Absolute zero in Celsius
    double absoluteZeroCelsius = -273.15;
    
    // Convert to Kelvin
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToKelvin(absoluteZeroCelsius), 0.0);
    
    // Convert to Fahrenheit
    EXPECT_NEAR(TemperatureConverter::celsiusToFahrenheit(absoluteZeroCelsius), -459.67, epsilon);
}

TEST_F(TemperatureConverterTest, SpecialPoints_WaterFreezingBoiling) {
    // Water freezing point
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(0.0), 32.0);
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToKelvin(0.0), 273.15);
    
    // Water boiling point
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(100.0), 212.0);
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(100.0), 373.15, epsilon);
}

TEST_F(TemperatureConverterTest, SpecialPoints_BodyTemperature) {
    // Normal body temperature in Fahrenheit
    double bodyTempF = 98.6;
    double bodyTempC = TemperatureConverter::fahrenheitToCelsius(bodyTempF);
    
    EXPECT_NEAR(bodyTempC, 37.0, 0.1);
}

TEST_F(TemperatureConverterTest, SpecialPoints_SameValueInCelsiusAndFahrenheit) {
    // -40°C = -40°F
    EXPECT_DOUBLE_EQ(TemperatureConverter::celsiusToFahrenheit(-40.0), -40.0);
    EXPECT_DOUBLE_EQ(TemperatureConverter::fahrenheitToCelsius(-40.0), -40.0);
}

// ============================================
// Edge Cases and Boundary Tests
// ============================================

TEST_F(TemperatureConverterTest, EdgeCase_VeryHotTemperatures) {
    // Surface of the sun approximation
    EXPECT_NEAR(TemperatureConverter::celsiusToKelvin(5500.0), 5773.15, epsilon);
}

TEST_F(TemperatureConverterTest, EdgeCase_VeryCloseToAbsoluteZero) {
    EXPECT_NEAR(TemperatureConverter::kelvinToCelsius(0.01), -273.14, epsilon);
}

TEST_F(TemperatureConverterTest, EdgeCase_PrecisionCheck) {
    // Test floating-point precision
    double temp = 123.456789;
    double f = TemperatureConverter::celsiusToFahrenheit(temp);
    double c = TemperatureConverter::fahrenheitToCelsius(f);
    
    EXPECT_NEAR(temp, c, 0.000001);
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
