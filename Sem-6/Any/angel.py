import speech_recognition as sr
from pydub import AudioSegment

# Path to the audio file
audio_path = r"E:\kontolsu.m4a"

# Initialize recognizer
recognizer = sr.Recognizer()

# Convert the m4a file to wav format
audio = AudioSegment.from_file(audio_path, format="m4a")
wav_path = r"E:\VSC\Sem-6\Any\audio.wav"
audio.export(wav_path, format="wav")

# Load the wav file
with sr.AudioFile(wav_path) as source:
    audio_data = recognizer.record(source)
    # Recognize (convert from speech to text)
    try:
        text = recognizer.recognize_google(audio_data, language="id-ID")
        print(text)
    except sr.UnknownValueError:
        print("Maaf, tidak dapat mengenali kata-kata dalam rekaman.")
    except sr.RequestError as e:
        print(f"Error: {e}")