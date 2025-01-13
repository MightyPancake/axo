import os
import re

def merge_markdown_files(thesis_dir, output_file):
    # Define a regex to match chapter directories (e.g., 0, 1, 2, etc.)
    chapter_dir_pattern = re.compile(r'^\d+$')
    
    # Collect chapters and their files
    chapters = []
    for item in sorted(os.listdir(thesis_dir), key=lambda x: int(x) if x.isdigit() else float('inf')):
        chapter_path = os.path.join(thesis_dir, item)
        if os.path.isdir(chapter_path) and chapter_dir_pattern.match(item):
            chapter_files = sorted(
                [os.path.join(chapter_path, f) for f in os.listdir(chapter_path) if f.endswith('.md')]
            )
            chapters.append((item, chapter_files))
    
    # Open the output file
    with open(output_file, 'w', encoding='utf-8') as out:
        for chapter_num, files in chapters:
            out.write(f"# Chapter {chapter_num}\n\n")  # Optional: Add a chapter heading
            for file_path in files:
                try:
                    with open(file_path, 'r', encoding='utf-8') as md_file:
                        out.write(md_file.read())
                        out.write("\n\n")  # Add spacing between files
                except UnicodeDecodeError as e:
                    print(f"Error decoding file: {file_path}")
                    print(f"Error details: {e}")
                    raise

    print(f"Markdown files merged into {output_file}")

# Replace 'thesis' with your directory and 'output.md' with your desired output file name
merge_markdown_files("thesis", "thesis.md")
