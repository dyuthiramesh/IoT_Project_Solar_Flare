#include <EloquentTinyML.h>
#include "solar_flare_model_esp32.h"

// Define input and output sizes
#define NUMBER_OF_INPUTS 10  // Updated based on your dataset (10 features)
#define NUMBER_OF_OUTPUTS 3   // Adjust based on your output classes (common, moderate, severe flares)

#define TENSOR_ARENA_SIZE 5*1024  // Adjust based on model size

// Initialize the model with the appropriate input/output sizes and tensor arena size
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);  // Start serial communication
    ml.begin(solar_flare_model_esp32);  // Load the TensorFlow Lite model
}

float fResult[NUMBER_OF_OUTPUTS] = {0};
float fRes = NULL;

// Define the input data as a 2D array (4 samples, each with 10 features)
float inputData[4][NUMBER_OF_INPUTS] = {
    {-1.8787969, -0.28223274, -0.3865936, -0.7048794, 0.02165439, 0.03122059, 0.15428138, -0.18893459, -0.11433257, 0.3},
    {1.72982439, -0.73198794, -0.44449491, 1.25893309, -0.54462844, -0.23754798, 0.66876918, -0.18893459, 0.39783594, 0.4},
    {-0.54517599, -0.67576854, -0.79190278, -0.56944406, -0.62552599, -0.59590607, -0.87469423, -0.3006034, -0.31919997, 0.5},
    {-0.93741743, 0.89837465, 0.77143262, -0.77259708, 2.44858083, 2.00219009, 0.41152528, 2.04444149, 2.24164257, 0.6}
};

void loop() {
    for (int i = 0; i < 4; i++) { // Loop through each input set
        initfResult(fResult);
        fRes = ml.predict(inputData[i], fResult);  // Make a prediction
        
        Serial.print("\nThe output value returned for input ");
        Serial.print(i + 1); // Print which input is being processed
        Serial.print(" is:\n");
        Serial.println(fRes);  // Print the prediction result
        
        displayOutput(fResult);  // Print all class probabilities
    }

    delay(5000); // 5 seconds delay between predictions
}

// Initialize the result array to 0
void initfResult(float *fResult) {
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        fResult[i] = 0.0f;
    }
}

// Display the output result probabilities for each class
void displayOutput(float *fResult) {
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        Serial.print(fResult[i]);
        Serial.print(" ");  // Print the class probability for each class
    }
    Serial.println(); // New line for better output readability
}