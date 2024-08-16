import React, { useState, useEffect } from "react";
import {
  View,
  Text,
  Image,
  SafeAreaView,
  ScrollView,
  StyleSheet,
} from "react-native";
import * as SecureStore from "expo-secure-store";

export default function StoreScreen() {
  const [storeLocation, setStoreLocation] = useState("");
  const [imagePath, setImagePath] = useState(null);
  const [imageError, setImageError] = useState(false);

  useEffect(() => {
    // Fetch store location from secure storage
    const fetchStoreLocation = async () => {
      const storedLocation = await SecureStore.getItemAsync("storeLocation");
      setStoreLocation(storedLocation || "Unknown Store");
    };

    // Load image path
    const fetchImagePath = () => {
      try {
        const path = require("../assets/path_image.jpg");
        console.log("Image path:", path);
        setImagePath(path);
      } catch (error) {
        console.error("Error loading image:", error);
        setImageError(true);
      }
    };

    fetchStoreLocation();
    fetchImagePath();
  }, []);

  return (
    <SafeAreaView style={styles.safeArea}>
      <ScrollView contentContainerStyle={styles.container}>
        <Text style={styles.text}>Store Location: {storeLocation}</Text>
        {imageError ? (
          <Text style={styles.errorText}>Error loading image</Text>
        ) : (
          imagePath && (
            <View style={styles.imageContainer}>
              <Image
                source={imagePath}
                style={styles.image}
                resizeMode="contain"
                onError={() => setImageError(true)} // Handle runtime errors
              />
            </View>
          )
        )}
      </ScrollView>
    </SafeAreaView>
  );
}

// Styles for the StoreScreen component
const styles = StyleSheet.create({
  safeArea: {
    flex: 1,
  },
  container: {
    flexGrow: 1,
    padding: 20,
    justifyContent: "center",
    alignItems: "center",
  },
  text: {
    fontSize: 18,
    color: "#1d3557",
    marginBottom: 20,
    textAlign: "center",
  },
  imageContainer: {
    width: "100%",
    height: 200,
    justifyContent: "center",
    alignItems: "center",
    marginTop: 20,
  },
  image: {
    width: "100%",
    height: "100%",
    aspectRatio: 16 / 9, // Adjust this for landscape orientation
  },
  errorText: {
    fontSize: 16,
    color: "red",
    marginTop: 20,
    textAlign: "center",
  },
});

/*
 * This file defines the StoreScreen component, which displays the store location and a corresponding image.
 *
 * The component includes the following elements:
 * - 'SafeAreaView': Ensures that the content is rendered within the safe area boundaries of a device.
 * - 'ScrollView': Allows the content to be scrollable if it overflows the screen size.
 * - 'Text': Displays the store location.
 * - 'Image': Displays the image in landscape mode.
 * - 'Text' (errorText): Displays an error message if the image fails to load.
 *
 * The store location is fetched from secure storage, and the image is loaded from local assets.
 * If the image fails to load, an error message is displayed instead.
 *
 * Style definitions are provided at the bottom of the file to maintain visual consistency.
 */
