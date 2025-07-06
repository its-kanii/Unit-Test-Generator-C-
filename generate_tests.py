import subprocess
import yaml

# Load YAML instruction
with open("refine_tests.yaml", "r") as f:
    instructions = yaml.safe_load(f)

prompt = instructions["instruction"]

# Read current unit test
with open("test/test_controllers.cc", "r") as f:
    code = f.read()

# Call Ollama
result = subprocess.run(
    ["ollama", "run", "llama3"],  # or the model you used
    input=f"{prompt}\n\nHere is the unit test code:\n```cpp\n{code}\n```",
    text=True,
    capture_output=True
)

# Save refined output
with open("test/test_controllers_refined.cc", "w") as f:
    f.write(result.stdout)

print("✅ Refined test written to test_controllers_refined.cc")

