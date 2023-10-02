
# How to Make a Pull Request (PR) on GitHub

## Introduction

A Pull Request (PR) is a way to contribute your changes to an open-source project hosted on GitHub. It allows you to propose your changes to the project maintainers and collaborate with the community. Here's a step-by-step guide on how to make a PR:

## Steps

### 1. Fork the Repository

- Go to the GitHub repository you want to contribute to.

- Click the "Fork" button in the top-right corner. This creates a copy of the repository under your GitHub account.

### 2. Clone Your Fork

- On your forked repository, click the "Code" button and copy the URL of your repository.

- Open your terminal and run the following command, replacing `<your-fork-url>` with the copied URL:

  ```bash
  git clone <your-fork-url>
  ```

### 3. Create a New Branch

- Change into the directory of the cloned repository:

  ```bash
  cd <repository-name>
  ```

- Create a new branch for your changes. It's a good practice to name your branch descriptively:

  ```bash
  git checkout -b feature/my-feature
  ```

### 4. Make Your Changes

- Make the necessary changes to the code, documentation, or files in the repository.

### 5. Stage and Commit Your Changes

- Stage your changes for commit:

  ```bash
  git add .
  ```

- Commit your changes with a descriptive message:

  ```bash
  git commit -m "Add feature: my feature"
  ```

### 6. Push Your Changes

- Push your branch to your forked repository on GitHub:

  ```bash
  git push origin feature/my-feature
  ```

### 7. Create a Pull Request

- Go to your forked repository on GitHub.

- You should see a notification suggesting you create a PR. Click on it.

- Review your changes and provide a clear description of your PR.

- Click the "Create Pull Request" button.

### 8. Collaborate and Iterate

- Project maintainers will review your PR, suggest changes, or merge it into the main branch.

- Engage in discussions and make any necessary changes based on feedback.

- Congratulations! You've successfully made a PR and contributed to an open-source project.

