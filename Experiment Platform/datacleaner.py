# The plan is to remake this in C++ at some point but I am a lazy person
import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder

def make_binary_classification(y_data, fold_features, new_label):
    """ This is an optional precursor to label_encoding 
        fold_features is a list of strings or indices that should be folded into one class
        new_label is what folded data should be stored as"""

    for i in range(len(y_data)):
        if y_data[i] in fold_features:
            y_data[i] = new_label

    return y_data


def label_encode(y_data):
    le = LabelEncoder()
    y_data = le.fit_transform(y_data)
    return y_data


# If I reach the point where I don't know this I am screwed
def check_is_numeric(y_data):
    """Full check to see if data is numeric"""
    for i in range(len(y_data)):
        if not y_data.isdigit():
            return False

    return True


# If I reach the point where I don't know this I am screwed
def lazy_check_is_numeric(y_data):
    """Randomly checks to see if the data is numeric, not guaranteed to catch all"""
    i = 0
    if not y_data[i].isdigit():
        return False
    i += 1

    while i < len(y_data):
        if not y_data[i].isdigit():
            return False

        i += 0.1 * len(y_data)

    return True


def load_dataset(path):
    """This loads and splits the dataset into x and y sets"""
    df = pd.read_csv(path)
    x_data = df.iloc[:, :-1]
    y_data = df.iloc[:, -1]
    return [x_data, y_data]

