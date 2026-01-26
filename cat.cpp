
function expBySquare(k, n, mod)
    local res = 1
    while n > 0 do
        if (n & 1) ~= 0 then
            res = (res * k) % mod
        end
        k = (k * k) % mod
        n = n >> 1
    end
    return res

function toBase10(s, b)
    local d10 = 0
    for i = 1, #s do
        local c = s:sub(i,i)
        d10 = d10 * b + (tonumber(c) or 0)
    end
    return d10
end
