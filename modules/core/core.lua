axo = {}

function _quote(v)
  s = tostring(v)
  if s then
    return "\"" .. s .. "\""
  end
  error("Couldn't quote value.")
end

function axo.print(exprs)
  res = "printf(\""
  for _, e in ipairs(exprs) do
    res = res .. "%" .. axo.getFmtString(e.typ)
  end
  res = res .. '\\n"'
  for _, e in ipairs(exprs) do
    res = res .. "," .. e.value
  end
  return res .. ")"
end

function axo.setFlags(libs)
  local res = ""
  for _, l in ipairs(libs) do
    res = res .. "\n#flag " .. _quote(l)
  end
  return res
end

function axo.getFmtString(t)
  local primitives_tab = {int = "d", byte = "c"}
  if t.primitive then
    return primitives_tab[t.primitive] or "d"
  elseif t.pointer then
    local st = t.pointer
    if st.primitive == "byte" then
      return "s"
    else
      return "x"
    end
  end
end

function axo.getOS()
    -- Check for Windows environment variable
    local os_name = os.getenv("OS")
    if os_name and os_name:find("Windows") then
        return "Windows"
    end

    -- Try using `uname` for Unix-like systems (Linux, macOS)
    local handle = io.popen("uname -s 2>/dev/null")
    if handle then
        local result = handle:read("*a")
        handle:close()
        if result and result:match("Linux") then
            return "Linux"
        elseif result and result:match("Darwin") then
            return "macOS"
        elseif result and result:match("%S") then
            return result:gsub("\n", "")  -- trim newline and return the result
        end
    end

    -- If all else fails, return "Unknown OS"
    return "unknown"
end

axo.os = axo.getOS()
os_str = _quote(axo.os)


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

