# generated from rosidl_generator_py/resource/_idl.py.em
# with input from edgevision_msgs:msg/FaceDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FaceDetection(type):
    """Metaclass of message 'FaceDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('edgevision_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'edgevision_msgs.msg.FaceDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__face_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__face_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__face_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__face_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__face_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FaceDetection(metaclass=Metaclass_FaceDetection):
    """Message class 'FaceDetection'."""

    __slots__ = [
        '_track_id',
        '_person_name',
        '_is_known',
        '_confidence',
        '_x1',
        '_y1',
        '_x2',
        '_y2',
    ]

    _fields_and_field_types = {
        'track_id': 'int32',
        'person_name': 'string',
        'is_known': 'boolean',
        'confidence': 'float',
        'x1': 'int32',
        'y1': 'int32',
        'x2': 'int32',
        'y2': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.track_id = kwargs.get('track_id', int())
        self.person_name = kwargs.get('person_name', str())
        self.is_known = kwargs.get('is_known', bool())
        self.confidence = kwargs.get('confidence', float())
        self.x1 = kwargs.get('x1', int())
        self.y1 = kwargs.get('y1', int())
        self.x2 = kwargs.get('x2', int())
        self.y2 = kwargs.get('y2', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.track_id != other.track_id:
            return False
        if self.person_name != other.person_name:
            return False
        if self.is_known != other.is_known:
            return False
        if self.confidence != other.confidence:
            return False
        if self.x1 != other.x1:
            return False
        if self.y1 != other.y1:
            return False
        if self.x2 != other.x2:
            return False
        if self.y2 != other.y2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def track_id(self):
        """Message field 'track_id'."""
        return self._track_id

    @track_id.setter
    def track_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'track_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'track_id' field must be an integer in [-2147483648, 2147483647]"
        self._track_id = value

    @builtins.property
    def person_name(self):
        """Message field 'person_name'."""
        return self._person_name

    @person_name.setter
    def person_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'person_name' field must be of type 'str'"
        self._person_name = value

    @builtins.property
    def is_known(self):
        """Message field 'is_known'."""
        return self._is_known

    @is_known.setter
    def is_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_known' field must be of type 'bool'"
        self._is_known = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def x1(self):
        """Message field 'x1'."""
        return self._x1

    @x1.setter
    def x1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x1' field must be an integer in [-2147483648, 2147483647]"
        self._x1 = value

    @builtins.property
    def y1(self):
        """Message field 'y1'."""
        return self._y1

    @y1.setter
    def y1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y1' field must be an integer in [-2147483648, 2147483647]"
        self._y1 = value

    @builtins.property
    def x2(self):
        """Message field 'x2'."""
        return self._x2

    @x2.setter
    def x2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x2' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x2' field must be an integer in [-2147483648, 2147483647]"
        self._x2 = value

    @builtins.property
    def y2(self):
        """Message field 'y2'."""
        return self._y2

    @y2.setter
    def y2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y2' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y2' field must be an integer in [-2147483648, 2147483647]"
        self._y2 = value
