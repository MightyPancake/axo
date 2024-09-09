axo = {}

os_str = "\"Linux\""

function axo.get(v)
  local s = v
  local t = type(v)
  if t == "string" then
    return v
  elseif t == "function" then
    s = v()
    if type(s) == "string" then
      return s
    else
      error("Macro function returned a non-string value.")
    end
  else
    error("Macro doesn't return a string or a function that returns a string")
  end
end

