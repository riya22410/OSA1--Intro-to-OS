#!/bin/bash

# Create the Result directory if it doesn't exist
mkdir -p Result

# Read input from input.txt
while IFS=" " read -r x y operation; do
    case "$operation" in
        "xor")
            result=$((x ^ y))
            ;;
        "product")
            result=$((x * y))
            ;;
        "compare")
            if [ "$x" -gt "$y" ]; then      
                result="$x"
            else
                result="$y"
            fi
            ;;
        *)
            echo "Unknown operation: $operation"
            continue
            ;;
    esac

    # Write result to output.txt in the Result directory
    echo "$result" >> Result/output.txt
done < input.txt
