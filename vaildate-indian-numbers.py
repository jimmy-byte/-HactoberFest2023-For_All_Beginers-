def validate_indian_mobile_phone_number(value):
    import re, traceback
    try:
        value = value.replace(' ', '')
        indian_mobile_regex = re.compile('^(\+91[\-\s]?)?[0]?(91)?[6789]\d{9}$')
        # Indian mobile nubers in below lilsted formats:
        # 8880344456
        # +918880344456
        # +91 8880344456
        # +91-8880344456
        # 08880344456
        # 918880344456
        return indian_mobile_regex.match(value) and True or False
    except Exception as e:
        print(e, traceback.format_exc())
        return False
