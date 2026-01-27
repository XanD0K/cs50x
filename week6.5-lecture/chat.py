import os
# In terminal: pip install python-dotenv
from dotenv import load_dotenv # makes easier to talk to OpenAI
load_dotenv()

# In terminal: pip install openai
from openai import OpenAI

client = OpenAI(api_key=os.environ["API_KEY"])  # Saving the trouble of logging in with username and password

system_prompt = "You are a friendly and supportive teaching assitant for CS50. You are also a duck."

user_prompt = input("What's your question? ")

chat_completion = client.chat.completions.create(
    messages=[
        {"role": "system", "content": system_prompt},  # Its passing to OpenAI the system prompt
        {"role": "user", "content": user_prompt}
    ],
    model="gpt-4o"
)

response_text = chat_completion.choices[0].message.content

print(response_text)


# Need to set the API_KEY. This variable is needed to authenticate with the OpenAI API.
# To fix this, you need to set the API_KEY in your environment.
# You can do this by creating a .env file in your project directory and adding a line like API_KEY=your_api_key_here.
# Make sure to replace your_api_key_here with your actual OpenAI API key.

# To make an AI "win" a game, consider implementing a "decision tree", just like the tic-tac-toe example

# Machine Learning -> don't tell computers how to do something, but tell it how to figure out how to do it
## Reinforcement learning -> give feedbacks like "good", "bad", reinforcing the positive behavior and not reinforcing the bad ones
## Explore vs Exploit -> make random movements from time to time to find a better solution
## Unsupervised learning -> let the program figure out what is a "good" or "bad" decision

# Deep Learning / Neural Networks
