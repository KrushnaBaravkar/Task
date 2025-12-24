import requests

API_KEY = "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"  # Paste your key here
MODEL = "llama3-70b-8192"   # try "llama3-70b-8192"

def llm_agent(prompt):
    url = "https://api.groq.com/openai/v1/chat/completions"      

    headers = {
        "Authorization": f"Bearer {API_KEY}",
        "Content-Type": "application/json"
    }

    payload = {
        "model": MODEL,
        "messages": [
            {"role": "user", "content": prompt}
        ],
        "temperature": 0.5           
    }

    response = requests.post(url, headers=headers, json=payload)

    if response.status_code == 200:
        result = response.json()
        reply = result['choices'][0]['message']['content']
        return reply
    else:
        return f"Error: {response.status_code} - {response.text}"

# 🔍 Test the agent
if __name__ == "__main__":
    prompt = input("What can i do for you : ")
    # print("User Prompt:", prompt)
    response = llm_agent(prompt)
    print("LLM Response:", response)
